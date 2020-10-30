import serial
import time
import datetime
import pymysql

ser=serial.Serial('COM3',9600)
conn = pymysql.connect(host='localhost', user='user1', password='98765',
                       db='testmydb',charset='utf8');
cursor = conn.cursor()


while True:
    if ser.readable():
        res=ser.readline()
        print(res.decode()[:len(res)-1])
        timestamp = str(time.time())
        timestamp = str(datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S'))
        print(timestamp)
        sql="INSERT INTO sos (time,contents) VALUES (%s,%s)"
        val=(timestamp,res)
        cursor.execute(sql,val)
        conn.commit()
        
