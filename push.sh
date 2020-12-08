#!/bin/sh

read -p "enter commit message: " commit_message
git add .
git commit -m "$commit_message"
git push origin master
