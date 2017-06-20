#!/bin/bash
# 产品ID, 版本, 图标, 下载地址, 大小 
product_id=`curl -G "http://127.0.0.1:8888/product_from_name" --data-urlencode "product_name=$1" | jq '.product.product_id'`
[[ -z "$product_id" ]] && echo "------------------->" $1
curl -X POST http://127.0.0.1:8888/release -d "product_id=$product_id&version=$2&icon_url=$3&download_url=$4&changelog=Change Log&package_size=$5&package_type=1&release_grade=1" | jq .
