#!/usr/bin/env python

import json

sink1 = {
    "sink": {
        "type": "stdout_sink_mt",
        "level": "trace"
        }
    }

sink2 = {
    "sink": {
        "type": "rotating_file_sink_mt",
        "file_name": "logs/proxy.log",
        "max_file_size": 5000000,
        "max_files": 10
        }
    }

log = {
    "level": "trace",
    "sinks": [sink1, sink2]
    }

proxy = {
    # 1 - forwarder
    # 2 - streamer
    # 3 - bus
    "type": 1,
    "front_addr": "@tcp://*:9990",
    "backend_addr": "@tcp://*:9991"
    }

cfg = {
    "zod": {
        "proxy": proxy
        },
    "log": log
    }

with open('proxy.json', 'w') as f:
    json.dump(cfg, f, sort_keys=True, indent=4)
