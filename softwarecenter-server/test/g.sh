#!/bin/bash
CURL="curl -X POST http://127.0.0.1:8888/product -d"
for f in /usr/share/applications/*.desktop
do

	name="`grep '^Name\[zh_CN\]=' $f | head -1`"
	[[ -z $name ]] && name="`grep '^Name=' $f | head -1`"
	[[ -z $name ]] && continue

	comment="`grep '^Comment\[zh_CN\]=' $f | head -1`"
	[[ -z $comment ]] && comment="`grep '^Comment=' $f | head -1`"
	[[ -z $comment ]] && continue
	icon="`grep '^Icon=' $f`"
	[[ -z $icon ]] && continue

	categories="`grep 'Categories=' $f`"
	categories=${categories#*=}
	categories=${categories%%;*}
	[[ -z "${categories}" ]] && categories=Other

	pk="`dpkg -S $f | cut -d: -f1`"
	[[ -z "$pk" ]] && continue

	vendor="`dpkg -s $pk| grep ^Maintainer:`"
	url="`dpkg -s $pk| grep ^Homepage:`"
	version="`dpkg -s $pk| grep ^Version:`"
	size="`dpkg -s $pk| grep ^Installed-Size:`"

	echo "${name#*=}|${comment#*=}|${categories}|${vendor#*: }|${url#*: }|${icon#*=}|${version#*:}|${size#*:}"
done
