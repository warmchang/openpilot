# server -> client ping

Every 60 seconds the server sends a ping to the client. If the client doesn't respond within 20
seconds, the server fails the connection with a timeout error (1011). If the client responds the
ping time is written to the database.


# client -> server ping

The client to server ping is not implemented.

We could implement this to run when the device is active/onroad to try to detect whether the
connection has been dropped.


# socket keepalive

The websocket sockopts default to having TCP keepalive enabled. This should help prevent the
connection being dropped, but it has the downside of preventing the modem from idling.

- try disabling it - does it affect performance or power usage?

## current websocket sockopts

```
SO_KEEPALIVE: 1
TCP_KEEPIDLE: 30
TCP_KEEPINTVL: 10
TCP_KEEPCNT: 3
TCP_USER_TIMEOUT: 0
```


# websocket timeout

The websocket timeout is set to 30 seconds, which is applied to the underlying socket. Previously
this was set to 1 second, but was increased since the frames were too big. Frames are now split.

- try decreasing the timeout
  - should make connecting more aggressive - if the connection is dead, we fail fast
  - doesn't affect power/modem usage when idle


# swaglog / low priority send queue

The log_handler checks for new swaglog files every 10 seconds and uploads them. The logs get
rotated every 60 seconds so the modem would be woken up for this too. They are already added to the
`low_priority_send_queue`, so it might be possible wait until the modem becomes active from main
queue activity and then send the low priority logs soon after.


# manage_athenad

the manager waits 5 seconds before restarting athena after it dies.

- try decreasing this but backoff if it keeps dying



- responding to athena method requests (indeterminate)
- sending swaglog (approx every 60 seconds)
- keepalive when idle (after 30 seconds) every 10 seconds!

- we might not need to send a keepalive often for cellular networks
  - https://developer.att.com/video-optimizer/docs/best-practices/periodic-transfers#:~:text=Best%20Practice%20Recommendation
  - AT&T seems to suggest "every several minutes" is good

-
