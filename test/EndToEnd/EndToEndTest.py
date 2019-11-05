import subprocess
import requests
import unittest
import json
import pytest
from datetime import datetime

class EndToEndTest(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def _grep_file(self, file_name, strings):
        with open(file_name) as f:
            buffer = f.read()
            return (str in buffer for str in strings)

    def _grep_logs(self, strings, filter_time=None):
        if not filter_time:
            return self._grep_file('logs/potato.log', strings)
        else:
            s, e = filter_time
            lines = []
            with open('logs/potato.log') as f:
                for line in f.readlines():
                    date = line[1:24]
                    try:
                        t = datetime.strptime(date, '%Y-%m-%d %H:%M:%S.%f')
                        if t >= s and t <= e:
                            lines.append(line)
                    except ValueError as err:
                        pass
            
            return (any(str in line for line in lines) == True for str in strings)

    def test_potato_works(self):
        """ Test if potato responds correctly """
        r = requests.get('http://localhost:8080')
        self.assertEqual(r.status_code, 200)

    def test_potato_logger(self):
        logs = ['STARTING POTATO SERVER', 'Server starts listening at port 8080 and maxconnections=3']
        self.assertTrue(all(self._grep_logs(logs)) == True)

        start = datetime.now()
        r = requests.get('http://localhost:8080')
        self.assertEqual(r.status_code, 200)
        end = datetime.now()

        logs = [
            'Accepted new connection socket fd=', 'Writing response: HTTP/1.1 200 OK',
        ]
        self.assertTrue(all(self._grep_logs(logs, filter_time=(start, end))) == True)
    
    def test_method_not_allowed(self):
        r = requests.get('http://localhost:8080/say_hi')
        self.assertEqual(r.status_code, 200)

        start = datetime.now()
        r = requests.post('http://localhost:8080/say_hi', data=json.dumps({'msg': 'hi'}))
        end = datetime.now()
        self.assertEqual(r.status_code, 405)
        self.assertEqual(r.text, 'Method Not Allowed')

        logs = ('Method Not Allowed', 'Writing response: HTTP/1.1 405 OK')
        self.assertTrue(all(self._grep_logs(logs, filter_time=(start, end))) == True)
        
