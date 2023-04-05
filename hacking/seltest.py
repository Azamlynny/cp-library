import subprocess
from bs4 import BeautifulSoup
import requests
import os
import time
from tqdm import tqdm
import sys

contest_id = '1811'
problem_id = 'F'
directory = contest_id + '/' + problem_id

replace = {'&quot;': '\"', '&gt;': '>', '&lt;': '<', '&amp;': '&', "&apos;": "'"}
languages = {'GNU C++20 (64)', 'GNU C++14', 'GNU C++11', 'GNU C++17'} # , 'Java 8':'Java 11.0.5', 'Python 3': 'Python 3.7.2', 'Python 2':'Python 2.7.15'

def parse(code):
	for key in replace.keys():
		code = code.replace(key, replace[key])
	return code

#fetches the code corresponding to the parameter url
def getCode(submission_url, submission_id, contest_id):
    source = requests.get(submission_url).text
    soup = BeautifulSoup(source, 'html.parser')
    language = soup.findAll('td')[3].text[6:-6]
    # print(language)
    if language not in languages:
        return
    code = soup.findAll('pre')[0].text
    code = parse(code).replace('\r', '')
    if code != '':
        print("Sucessfully fetched", submission_id + ".cpp")
        filewrite = open(directory + '/' + submission_id + '.cpp', 'w')
        filewrite.write(code)
        filewrite.close()


if (not os.path.exists(directory)):
    os.makedirs(directory)

fetch = False

page = 1
while fetch:
    url = "http://codeforces.com/contest/"+contest_id+"/status/"+problem_id+"/page/" + str(page) + "?order=BY_ARRIVED_DESC"
    print ("Parsing page:", page)
    try:
        source = requests.get(url).text
        soup = BeautifulSoup(source, 'html.parser')
        submissions = soup.findAll('a', {'class':'view-source'})
        
        for submission in submissions:
            submission_url = "http://codeforces.com" + submission['href']
            try:
                getCode(submission_url, submission['submissionid'], contest_id)
            except:
                print("Failed to fetch:", submission_url)
                continue
            time.sleep(2)

    except:
        print("Finished parsing on page:", page)

    page+=1

if (not os.path.exists(os.path.join(directory,'compiled'))):
    os.makedirs(os.path.join(directory,'compiled'))

run = True

if(not run):
    for file in os.listdir(directory):
        file_name = os.path.splitext(file)[0]
        file_ext = os.path.splitext(file)[1]
        os.system('g++ ' + os.path.join(directory, file_name)+file_ext + ' -o ' + os.path.join(directory,'compiled',file_name) + ' -O2')    
else:
    # load input and output
    with open('input.txt', 'r') as myfile: 
        test_input = myfile.read()
    with open('output.txt', 'r') as myfile: 
        test_output = myfile.read()

    dirs = os.listdir('1811\F\compiled')
    # print(len(dirs))
    hackable = []

    for i in tqdm(range(len(dirs))):
        file = dirs[i]
        # print(os.path.splitext(file)[0])
        cmd = 'more input.txt | 1811\F\compiled\\' + file
        # print (cmd)
        test = subprocess.check_output(cmd, shell=True)
        # os.system(cmd)
        # print(test)
        test = test.lower()
        # test = test[4:3]
        if ('yes' in str(test)):
            hackable.append(os.path.splitext(file)[0])
            # print(os.path.splitext(file)[0])
        # time.sleep(0.5)       
        # lines = sys.stdin.readline()
        # print("lines", lines)

    
    for h in hackable:
        print(h)
        
        
