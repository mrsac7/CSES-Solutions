import os


WINDOWS_LINE_ENDING = b'\r\n'
MAC_LINE_ENDING = b'\r'
UNIX_LINE_ENDING = b'\n'

# relative or absolute file path, e.g.:
dir = "src/"
for filename in os.listdir(dir):
	file_path = dir+filename

	with open(file_path, 'rb') as open_file:
	    content = open_file.read()
	    
	content = content.replace(MAC_LINE_ENDING, UNIX_LINE_ENDING)

	with open(file_path, 'wb') as open_file:
	    open_file.write(content)