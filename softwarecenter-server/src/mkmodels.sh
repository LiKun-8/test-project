#!/bin/bash
MODELS=models
rm -rf $MODELS && mkdir $MODELS
CMDLINE="xo mysql://emindsoftwarecenter:1@localhost/emind_software_center --suffix .go -o $MODELS"
$CMDLINE
QUERY="$CMDLINE -a -N -M -B -T"

$QUERY ScProduct << ENDSQL
SELECT
    *
    FROM sc_product
ENDSQL

$QUERY ScCategory << ENDSQL
SELECT
    *
    FROM sc_category
ENDSQL

pushd models &>/dev/null
rm -f easyjson.go
sed 's/`json:\(.*\)`/`json:\1 form:\1`/g' -i *.go
easyjson -all *.go
popd &>/dev/null
gofmt -w models

