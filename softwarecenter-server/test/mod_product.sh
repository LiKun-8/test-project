#!/bin/bash
O=${1-0} 
curl -X PUT http://127.0.0.1:8888/product/$O -d "product_name=桌面$O&vendor_name=一铭$O&url=www.emindsoft.com.cn&product_description=呵呵$O" | jq .
