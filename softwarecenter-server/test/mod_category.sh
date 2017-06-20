#!/bin/bash
O=${1-0}
curl -X PUT http://127.0.0.1:8888/category/$O -d "category_name=呵呵$O" | jq .
