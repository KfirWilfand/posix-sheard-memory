# posix-sheard-memory
This is repo is example of consumer and producer of posix sheard memory in Python and C

## Python  
### Installation 
```bash
cd python
pip3 install -r requirements.txt
```

### Run
```bash
python3 python-consumer.py 
```
or
```bash
python3 python-producer.py 
```
## C 
### Compile & Run
```bash
cd c
gcc c-producer.c utils.c utils.h
./a.out
```