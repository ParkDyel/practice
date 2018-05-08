import sys
import os.path
import csv
import math
import numpy

def read_tsv_file_to_list_dict(file, sep='\t'):
    "read tsv file and return as dictionary which have list in each key."
    with open(file) as fd:
        reader = csv.reader(fd,delimiter=sep)
        header = next(reader)     
        ret = dict({key: list() for key in header})
        for row in reader:
            for idx in range(len(header)):
                ret[header[idx]].append(row[idx])
    return ret          

def read_tsv_file_to_dict_list(file, sep='\t'):
    "read tsv file and return as dictionary list."
    with open(file) as fd:
        ret = list()
        for dict_data in csv.DictReader(fd,delimiter=sep):
            ret.append(dict_data)
    return ret

   
def main():
    if(len(sys.argv) < 2):                                         
        print('USAGE:python script.py targetFile (sep)')
        exit()

    file_path = '.' + os.path.sep + sys.argv[1]

    if(len(sys.argv) == 3):
        sep = sys.argv[2]
    if(os.path.isfile(file_path)):
        dict_list = read_tsv_file_to_dict_list(file_path)
    
    for idx, item in enumerate(dict_list):
        print( str(idx) + '\t' + str(item) )

    return
if __name__ == '__main__':
    main()

# def get_index_of_max_value(list_dicts, res_dict):
#     for key in list_dicts.keys():
#         value = max(list_dicts[key])
#         res_dict[key]['Max_Date'] = list_dicts['Date'][list_dicts[key].index(value)]
#         res_dict[key]['Max_Value'] = value
#     return res_dict

# def get_index_of_min_value(list_dicts, res_dict):
#     for key in list_dicts.keys():
#         value = min(list_dicts[key])
#         res_dict[key]['Min_Date'] = list_dicts['Date'][list_dicts[key].index(value)]
#         res_dict[key]['Min_Value'] = value
#     return res_dict

# def get_log_yield_close(data_list):
#     xn = list()
#     for idx in range(1, len(data_list)):
#         xn.append(math.log(float(data_list[idx]) / float(data_list[idx-1])))
#     print(xn)
#     return numpy.mean(xn), numpy.std(xn)
    