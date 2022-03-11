# network_tester
```sh
#only laptop
pip3 install pyqt5
pip3 install requests beautifulsoup4
```
<strong>Make sure that the Laptop and the drone are connected with the microhard</strong>

```sh
# laptop
python3 master.py <microhard_ip> <drone_ip> 10700
# drone
python3 slave.py <microhard_ip> <laptop_ip> 10700
```

![Main Screen](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/ee41b56f-809d-4fea-8584-0f154fa00125/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220311%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220311T125006Z&X-Amz-Expires=86400&X-Amz-Signature=0ea8bd04be5ef1d4afe038f42202d732f2af12cecb2241376e44ddcf63f4026a&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22&x-id=GetObject)
