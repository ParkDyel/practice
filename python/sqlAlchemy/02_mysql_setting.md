# Setting MySQL for Programming
1. MySQL 실행
    ```
    1| service mysql start
    2| service mysql status
    3| mysql -u root -p
    ```
2. [DB, Table, Row 생성](http://kwonnam.pe.kr/wiki/database/mysql/basic)
    ```
    mysql> create database ${dbName};
    mysql> show databases;
    mysql> usb dbname;
    // drop database [if exsits] ${dbName};
    mysql> CREATE TABLE tablename ( ${column_name1} INT PRIMARY KEY AUTO_INCREMENT, ${column_name2} VARCHAR(15) NOT NULL, ${column_name3} INT) ENGINE=INNODB;
    mysql> INSERT INTO tablename VALUES(값1, 값2, ...);
    ```
3. 