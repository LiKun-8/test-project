cut -d" " -f2 categories  | while read line; do ./add_category.sh $line;done
