#!/bin/bash

# 检查参数是否为空
if [ -z "$1" ]; then
  echo "请提供提交信息作为参数。"
  exit 1
fi

# 获取提交信息
commit_message="$1"

# 执行 git 命令
git add .
git commit -m "$commit_message"
git push

