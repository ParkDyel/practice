sudo yum install git docker -y
sudo usermod -aG docker $USER
sudo systemctl enable docker
sudo reboot
docker pull zabbix/zabbix-appliance
docker run --name some-zabbix-appliance -p 80:80 -p 10051:10051 -d zabbix/zabbix-appliance

docker pull zabbix/zabbix-agent
docker run --name some-zabbix-agent --link some-zabbix-appliance:zabbix-server -d zabbix/zabbix-agent

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
