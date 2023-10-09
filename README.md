# Breach Impact Assesment Algorithm

## Overview

This project aims to assist a security administrator in assessing the impact of a breach (e.g., a malware attack) on a network of Virtual Machines (VMs). Given a list of VMs and their connection types, the goal is to determine the risk to other VMs in the network when a specific VM has been infected. The severity of the impact will be determined by the connection type, with different connection types carrying varying levels of risk. The severity order is as follows: Peer-to-peer > TCP > UDP > ICMP

## Problem Statement

- You are provided with a list of VMs and their connection types with each other.
- The connection types can be UDP, TCP, ICMP, or Peer-to-peer.
- VMs are connected in a graph-like fashion, with connections between them.
- An infected VM ID is given as input.

## Usage

To use this algorithm, follow these steps:

1. Input the list of VMs and their connection types.
2. Provide the ID of the infected VM.
3. Execute the algorithm, which will return a list of infected VMs sorted by severity.

## Conclusion

This algorithm provides a systematic way to assess the impact of a breach on a network of VMs based on their connection types. It helps security administrators prioritize their response by identifying which VMs are at higher risk and need immediate attention.
