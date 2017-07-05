#!/bin/bash
check()
{
    [[ $1 -ne 0 ]] && exit 1
}

MODELS=models
rm -rf $MODELS/*.xo.go 
CMDLINE="xo mysql://emindsoftwarecenter:1@localhost/emind_software_center --suffix .xo.go -o $MODELS"
$CMDLINE
check $?

QUERY="$CMDLINE -a -N -M -B -T"

$QUERY ScProduct << ENDSQL
SELECT
    *
    FROM sc_product
ENDSQL
check $?

$QUERY ScCategory << ENDSQL
SELECT
    *
    FROM sc_category
ENDSQL
check $?

$QUERY ScProductAndRelease << ENDSQL
    SELECT 
    sc_product.ID, 
    sc_product.product_name, 
    sc_product.vendor_name, 
    sc_product.url,
    sc_product.product_description, 
    sc_release.version,
    sc_release.icon_url,
    sc_release.download_url,
    sc_release.package_size,
    sc_release.package_type,
    sc_release.release_date
    FROM sc_product INNER JOIN sc_release
    WHERE sc_product.ID = sc_release.ID
ENDSQL
check $?

pushd models &>/dev/null
rm -f *_easyjson.go
sed 's/`json:\(.*\)`/`json:\1 form:\1`/g' -i *.go
easyjson -all *.go
popd &>/dev/null
gofmt -w models

