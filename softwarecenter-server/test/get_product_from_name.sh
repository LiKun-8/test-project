#!/bin/bash
O=${1-2}
curl http://127.0.0.1:8888/product_from_name?product_name=$1 | jq .
