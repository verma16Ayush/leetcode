#
# @lc app=leetcode id=195 lang=bash
#
# [195] Tenth Line
#

# @lc code=start
# Read from the file file.txt and output the tenth line to stdout.
# cnt=0;

# while read line && [ $cnt -le 10 ];
# do
#     expr $cnt = $cnt + 1
#     if [ $cnt -eq 10 ]; then 
#         echo $line && exit 0
#     fi
# done < file.txt
cnt=0
while read line && [ $cnt -le 10 ]; do
  let 'cnt = cnt + 1'
  if [ $cnt -eq 10 ]; then
    echo $line
    exit 0
  fi
done < file.txt
# @lc code=end

