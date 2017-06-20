#!/bin/bash
curl -X POST http://127.0.0.1:8888/category -d "category_name=$1" | jq .
