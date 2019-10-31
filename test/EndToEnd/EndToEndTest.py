import subprocess
import requests
import unittest
import json
import pytest

class EndToEndTest(unittest.TestCase):
    def setUp(self):
        self.sb = subprocess.Popen('build/potato')

    def tearDown(self):
        self.sb.kill()

    def test_potato_works(self):
        """ Test if potato responds correctly """
        r = requests.get('http://localhost:8080')
        self.assertEqual(r.status_code, 200)
    
    @pytest.mark.skip()
    def test_method_not_allowed(self):
        r = requests.get('http://localhost:8080/say_hi')
        self.assertEqual(r.status_code, 200)
        r = requests.post('http://localhost:8080/say_hi', data=json.dumps({'msg': 'hi'}))
        self.assertEqual(r.status_code, 405)
        self.assertEqual(r.text, 'Method Not Allowed')
        
