# Python modules
import time
import mmap
import sys
import hashlib

# 3rd party modules
import posix_ipc

# Utils for this demo
import utils

PY_MAJOR_VERSION = sys.version_info[0]
params = utils.read_params()
data = """
{
  "array": [
    1,
    2,
    3
  ],
  "boolean": true,
  "color": "gold",
  "null": null,
  "number": 123,
  "object": {
    "a": "b",
    "c": "d"
  },
  "string": "Hello World"
}
"""

# Create the shared memory and the semaphore.
memory = posix_ipc.SharedMemory(params["SHARED_MEMORY_NAME"], posix_ipc.O_CREX,
                                size=params["SHM_SIZE"])

# MMap the shared memory
mapfile = mmap.mmap(memory.fd, memory.size)

# Once I've mmapped the file descriptor, I can close it without
# interfering with the mmap.
memory.close_fd()

# I seed the shared memory with a random string (the current time).

utils.write_to_memory(mapfile, data) 
                 