#1541056145
ifconfig 
#1541056188
curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.myhuaweicloud.com/repo/CentOS-Base-7.repo
#1541056196
yum makecache
#1541056206
yum repolist
#1541056211
yum -y install vim
#1541056227
yum -y install pstree
#1541056250
yum provides pstree
#1541056260
yum -y install psmisc
#1541056276
yum provides ip
#1541056286
yum -y install iproute
#1541056296
yum provides lftp
#1541056305
yum -y install lftp
#1541056338
yum list | grep "bash"
#1541056346
yum list | grep "bash-*"
#1541056356
yum list | grep "^bash-*"
#1541056370
yum -y install ^bash-*
#1541056378
yum -y install bash
#1541056388
yum -y install bash-completion.noarch 
#1541056409
yum -y install bash-doc.x86_64 
#1541056493
yum install bash-completion -y 
#1541056521
reboot
#1541056576
getenforce 
#1541056588
exit
