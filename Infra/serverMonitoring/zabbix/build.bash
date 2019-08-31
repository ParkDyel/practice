sudo yum install git docker -y && sudo usermod -aG docker $USER && sudo systemctl enable docker && sudo reboot
docker pull zabbix/zabbix-appliance
# docker run --name zabbix-appliance --restart always -p 80:80 -p 10051:10051 -d zabbix/zabbix-appliance 
docker run --name zabbix-appliance --restart always -p 80:80 -p 10051:10051 -d zabbix/zabbix-appliance

sudo vim /etc/postfix/main.cf
```bash
mynetworks = 127.0.0.0/8 [::ffff:127.0.0.0]/104 [::1]/128 172.16.0.0/12
inet_interfaces = all
```
sudo service postfix restart
172.16.0.1

docker pull zabbix/zabbix-agent
docker run --name zabbix-agent -p 10050:10050 -e ZBX_ACTIVE_ALLOW=true --link zabbix-appliance:zabbix-server --restart always -d zabbix/zabbix-agent

# zabbix server admin tool에서 ip 설정
docker exec some-zabbix-agent 

# monitoring 
sudo yum install git docker -y
sudo usermod -aG docker $USER
sudo systemctl enable docker
sudo reboot

docker pull zabbix/zabbix-agent
# passive
# docker run -p 10050:10050 --name some-zabbix-agent -e ZBX_HOSTNAME="dev" -e ZBX_SERVER_HOST="172.31.20.110" -e ZBX_ACTIVE_ALLOW=false -d zabbix/zabbix-agent

# active
docker run --name some-zabbix-agent -p 10050:10050 -e ZBX_HOSTNAME="service" -e ZBX_SERVER_HOST="172.31.20.110" -e ZBX_ACTIVE_ALLOW=true -d zabbix/zabbix-agent
