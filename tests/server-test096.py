#!/usr/bin/python

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer


class TestHTTPRequestHandler(BaseHTTPRequestHandler):
  def json_answer(self, msg):
    self.send_response(200)
    self.send_header("Content-type", "application/json")
    self.end_headers()
    self.wfile.write(msg)

  def do_GET(self):
    if self.path == '/api/1.0/projects':
      self.json_answer('[{"id": 1, "name": "Test project"}]')
    elif self.path == '/api/1.0/projects/1':
      self.json_answer('{"status": "Active", "name": "Test project", "created_at": "2011/10/23", "experiments": 1, "client": "Someone", "owner": "One engineer", "targets": 1}')
    elif self.path == '/api/1.0/projects/1/experiments':
      self.json_answer('[{"id": 1, "name": "first experiment"}]')
    elif self.path == '/api/1.0/projects/1/experiments/1':
      self.json_answer('{"status": "Starting", "launched_at": "2012/12/29 13:02", "runs": 2, "id": 1, "name": "first experiment"}')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets':
      self.json_answer('[{"id": 1, "name": "one target"}]')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets/1':
      self.json_answer('{"id": 1, "name": "one target"}')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets/1/runs':
      self.json_answer('[{"hash": "d82cd2cbe396b918104639376d143f87", "id": 1}, {"hash": "71a1e5f6d9f4518415485ee8d27a1a87", "id": 2}]')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets/1/runs/1':
      self.json_answer('{"version": "1.0-170-g3ff02e5c", "hash": "d82cd2cbe396b918104639376d143f87", "conf": "", "time": "11860.00", "sizered": "0.00", "speedup": "0.00", "id": 1, "uconf": "", "size": 240563}')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets/1/runs/2':
      self.json_answer('{"version": "1.0-170-g3ff02e5c", "hash": "71a1e5f6d9f4518415485ee8d27a1a87", "conf": "-Os", "time": "13220.00", "sizered": "46.58", "speedup": "-10.29", "id": 2, "uconf": "", "size": 128516}')
    else:
      self.send_response(404)


  def do_PUT(self):
    import urlparse
    if self.path == '/api/1.0/projects':
      length = int(self.headers.getheader('content-length'))
      values = dict(urlparse.parse_qsl(self.rfile.read(length)))
      if values['name'] == 'Test project' and values['client'] == 'Someone' and int(values['owner']) == 1:
        self.json_answer('{"status": "success", "id": 1}')
      else:
        self.json_answer('{"status": "failure", "message": "Invalid arguments passed during project creation"}')
    elif self.path == '/api/1.0/projects/1/experiments':
      length = int(self.headers.getheader('content-length'))
      values = dict(urlparse.parse_qsl(self.rfile.read(length)))
      if values['name'] == 'first experiment':
        self.json_answer('{"status": "success", "id": 1}')
      else:
        self.json_answer('{"status": "failure", "message": "Invalid argument while creating experiment"}')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets':
      length = int(self.headers.getheader('content-length'))
      values = dict(urlparse.parse_qsl(self.rfile.read(length)))
      if values['name'] == 'one target':
        self.json_answer('{"status": "success", "id": 1}')
      else:
        self.json_answer('{"status": "failure", "message": "Invalid argument while creating target"}')
    elif self.path == '/api/1.0/projects/1/experiments/1/targets/1/runs':
      length = int(self.headers.getheader('content-length'))
      values = dict(urlparse.parse_qsl(self.rfile.read(length), keep_blank_values=True))
      if values['hash'] == 'd82cd2cbe396b918104639376d143f87' and\
         values['version'] == '1.0-170-g3ff02e5c' and\
         values['conf'] == '' and\
         values['size'] == '240563' and\
         values['time'] == '11860.00':
        self.json_answer('{"status": "success", "id": 1}')
      elif values['hash'] == '71a1e5f6d9f4518415485ee8d27a1a87' and\
           values['version'] == '1.0-170-g3ff02e5c' and\
           values['conf'] == '-Os' and\
           values['size'] == '128516' and\
           values['time'] == '13220.00':
        self.json_answer('{"status": "success", "id": 2}')
      else:
        self.json_answer('{"status": "failure", "message": "Invalid arguments passed during run creation"}')
    else:
      self.send_response(404)


def main():
  import socket
  import sys
  # Find the right port to use
  port = 9000
  port_found = False
  while not port_found:
    server_address = ('', port)
    try:
      httpd = HTTPServer(server_address, TestHTTPRequestHandler)
    except socket.error:
      port = port + 1
    else:
      port_found = True

  # Write to a given file
  f = open('server.conf', 'w')
  f.write("port=%d" % (port))
  f.close()
  httpd.serve_forever()


if __name__ == '__main__':
  main()


