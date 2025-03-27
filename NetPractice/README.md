# Network Practice Exercise

This project is a network practice exercise from 42 School. The goal is to complete three exercises of varying difficulty levels by adjusting the networks shown.

I advice you to go trhough all the exlanation before to start the practice.

here a link where to practice on your browser: [https://pfalli.github.io/net_practice/]

## Project Overview

In this project, you will work on configuring network settings for different scenarios. You will need to take care of the following:

1. **IP Addresses**: Assign appropriate IP addresses to devices in the network.
2. **Switches**: Represent a single network segment where all connected devices are on the same subnet.
3. **Routers**: Connect different networks and route traffic between them.
4. **Routing Channels**: Define the destination and the next hop for routing traffic.

## Key Concepts

### IP Address Calculation
To calculate an IP address, you need to understand the structure of an IP address, which consists of four octets. Each octet can range from 0 to 255. For example, `192.168.1.1` is a valid IP address until '192.168.255.255'.
- Remember that those IP addresses are exclusively reserved for Private IP addresses, so they canno be used to connect to Internet. But we can create any kind of IP we want(42.3.4.5 to 255, 158.2.3.4 to 255 etc...)

192.168.0.0 – 192.168.255.255
172.16.0.0 – 172.31.255.255
10.0.0.0 – 10.255.255.255

### Netmask Calculation
A netmask is used to divide an IP address into subnets and specify the network's available hosts. For example, a netmask of `255.255.255.0` means that the first three octets are the network part, and the last octet is the host part.

![Screenshot 2024-10-14 125131](https://github.com/user-attachments/assets/1e5271d7-bb07-4fef-882b-f0c7531dd7fe)


### Routing
Routers use routing tables to determine the best path for forwarding packets. Each entry in the routing table includes a destination network and the next hop (the next router or device to which the packet should be sent).

![internet](https://github.com/user-attachments/assets/64d23435-3b6c-4c92-854e-8e46f511d53c)

### IP Range Table
Here is a table where we  can fin the IP addresses available to the relative Net Mask:
example: if the mask is /28 (or 255.255.255.240), the IP range is of 16, but the first one and the last one of the ranges are not usable, so we can use from 17 to 31. And so on with the other Masks.
look at practical exmaple on level 10 at next picture

![range table](https://github.com/user-attachments/assets/438439a3-22f5-4430-aff1-be194f79da63)


## Example Code

Here are some functions from the project that help with IP and netmask calculations: LEVEL 10 has to add random IP addreses and paying attention to not overlap the IP addresses respecting the Range Address between one network and the other one conencted by the Router:

![level10](https://github.com/user-attachments/assets/2e9bc973-a385-4742-a8ce-d3136d0ef686)

At this level, there are 4 different networks:

    Router R1 to Switch S1
    Router R1 to Router R2
    Router R2 to Client H4
    Router R2 to Client H3

1. The internet must be able to send its packets to all the hosts, so its destination must cover the range of networks of all the hosts.

Interface R11 and Interface R13 already have an IP address entered. This IP address only differs in its last byte. Interface R11 has for last byte 1, and Interface R13 has for last byte 254. To cover this wide range to IP addresses, we take a mask of /24 for the internet's destination. This destination will cover a range of 70.101.30.0 - 70.101.30.255.


2. When choosing the IP addresses, we must make sure of 2 things:

    The IP address is covered by the internet destination.
    The IP address range of the various networks does not overlap.

With the IP addresses already entered (greyed out), let's examine the ranges covered by the various networks:

    Router R1 to Switch S1 - Covers the range 70.101.30.0 - 70.101.30.127 (mask /25).
    Router R2 to Client H4 - Covers the range 70.101.30.128 - 70.101.30.191 (mask /26).
    Router R1 to Router R2 - Covers the range 70.101.30.252 - 70.101.30.255 (mask /30).
    Router R2 to Client H3 - ??? (mask ???).

The only IP addresses left for the network "Router R2 to Client H3" are 70.101.30.192 - 70.101.30.251. We can pick any mask that will let us take 2 IP addresses from that range to put in Interface R22 and Interface R31.


### If we have only the IP Address?

We can add any Net Mask we want, but paying attention to the eventual IP Range we need to set to other Network of the same Mask. Look at Level 10 for practical examples

### If we have only the Net Mask?

We can add any IP address we want, but taking in consideration that theaddresses 192..../172..../10.... cannot be connected to Internet because they are exclusivily Private IP addresses.
