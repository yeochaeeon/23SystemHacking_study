## Welcome 
<pre> 
Q. "S0VFUEVSe1dlbGNvbWVfdG9fdGhlXzR0aF9LRUVQRVJfQ1RGfQ==" 를 해석하여 KEEPER{...} 형식의 플래그 찾기
</pre>

<hr>

## Solution 

* KEEPER{...} 문자가 base64 방식으로 인코딩된 결과가 해석대상인 문자열인듯하다.
* ==과 같은 기호를 보아 base64방식으로 유추가 가능하다.
* 문제의 문자열을 base64 방식으로 디코딩을 해야한다.

### base64란?

* base64 인코딩이란 binary to text 체계로 이진데이터를 64진법으로 표현된 ascii코드 문자열 형태로 나타낸다.
* 기본적으로 6bit 마다 64자 기호로 인코딩된다. 
* 기호에는 "A-Z", "a-z", "0-9","+","/" 가 있고
* 비트가 모자랄 때는 "="(padding) 문자를 사용해 채운다.
* 인코딩 방법 : 문자열 -> ascii(decimal) -> binary -> 6bit cut -> decimal로 변환 -> base64 encode

## Tools 

> ## Encode or Decode base64 in python  
* decode 
```python

import base64

encoded_text = "S0VFUEVSe1dlbGNvbWVfdG9fdGhlXzR0aF9LRUVQRVJfQ1RGfQ=="
binary_data = base64.b64decode(encoded_text)
decoded_text = binary_data.decode('utf-8')

print(decoded_text)

```

* encode 
```python

# -*- coding: utf-8 -*-
import base64

# 인코딩할 데이터
original_data = b"important_message"

# Base64로 인코딩
encoded_data = base64.b64encode(original_data)

# 결과 출력 (바이너리 데이터 그대로 출력)
print(encoded_data)

```

> ## Encode or Decode base64 in Ubuntu

* Encode
    * echo : ``` echo "important_message" | base64```
    * get input until press "ctrl + D" : ```base64```

* Decode 
    * echo : ```echo "aW1wb3J0YW50X21lc3NhZ2U="```
    * get input until press "ctrl + D " : ```base64 --decode```


