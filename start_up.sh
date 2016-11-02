
#启动tracker程序
sudo /usr/bin/fdfs_trackerd ./conf/tracker.conf

#启动storage
sudo fdfs_storaged	./conf/storage.conf

#启动redis_server程序
redis-server ./conf/redis.conf
