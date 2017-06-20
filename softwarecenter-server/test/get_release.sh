#!/bin/bash
O=${1-2}
curl http://127.0.0.1:8888/release/$O | jq .
