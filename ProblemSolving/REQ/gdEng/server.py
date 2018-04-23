#! /usr/bin/python2

# import protocol buffers
import devicedata_pb2 as devicedata
import sys
import random
from datetime import datetime

# This function name mean initialize Device data, but now just set random data in each field.
def initDeviceData(deviceData):
    deviceData.temperature = random.randint(-20, 100)
    deviceData.ampereConsumption = random.randint(0, 200)
    deviceData.battery = random.randint(0, 99)
    deviceData.option = random.randint(0, 268435456)
    deviceData.power = random.randint(0,1)
    deviceData.insertTime = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print deviceData.ByteSize()
    

def getDeviceData(deviceData):
    for data in deviceData.device:
        print("\n\n")
        print ("Device Temperature(-20~100\'C):", data.temperature)
        print ("Device Current Consumption(0~200mA):", data.ampereConsumption)
        print ("Device Battery Status(0~99%):", data.battery)
        print ("Device Option:", data.option)
        if data.power == True:
            print ("Device Power Status: ON")
        else:
            print ("Device Power Status: OFF")
        print("Device Data Inserted Time:", data.insertTime)
#   if person.HasField('email'):

def main():
    # check it had proto data files. if not create the OUTPUT files.
    if len(sys.argv) == 1:
        print ("Default:", sys.argv[0], "OUTPUT.just.ignore")
        sys.argv.insert(1, "OUTPUT.just.ignore")
    elif len(sys.argv) != 2:
        print ("Usage:", sys.argv[0], "ADDRESS_BOOK_FILE")
        sys.exit(-1)

    # create DeviceData Obejct.
    device_data = devicedata.DeviceData()
    # device_data.IsInitialized()


    # Read data from the existing proto data files.
    try:
        fd = open(sys.argv[1], "rb")
        device_data.ParseFromString(fd.read())
        fd.close()
    except IOError:
        print (sys.argv[1] + ": Could not open file.  Creating a new one.")

    # push data in the proto data files.
    initDeviceData(device_data.device.add())

    # Write data to the proto data back to files in disk.
    fd = open(sys.argv[1], "wb")
    fd.write(device_data.SerializeToString())
    fd.close() 

    # create DeviceData Obejct.
    device_data2 = devicedata.DeviceData()
    # print (device_data2.__str__())

    # Read data from the existing proto data files.
    fd = open(sys.argv[1], "rb")
    device_data2.ParseFromString(fd.read())
    fd.close()

    getDeviceData(device_data2) 

if __name__ == '__main__':
    main()