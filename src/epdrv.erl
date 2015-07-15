-module(epdrv).

-define(DRIVER, "epdrv").

-export([
         open/0,
         close/1
        ]).

open() ->
  ok = erl_ddll:load_driver("priv", ?DRIVER),
  Port = open_port({spawn, ?DRIVER}, []),
  {ok, Port}.
  
close(Port) -> port_close(Port).
