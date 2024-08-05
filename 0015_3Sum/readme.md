# 15. 3Sum

## Problem

Given an integer array _nums_, return all the triplets _[nums[i], nums[j], nums[k]]_ such that _i != j_, _i != k_ and _j != k_, and _nums[i] + nums[j] + nums[k] == 0_.

The solution set must not contain duplicate triplets.

## Approach

My idea was to reduce the problem to the 2Sum problem which I have encountered before.
Given a sorted sequence, the 2Sum problem can be solved in linear time.
I can therefore sort the input, fix index _i_ and solve the 2Sum problem to obtain all _j-k_-combinations with sum _-nums[i]_. Doing this for every possible _i_ I therefore obtain a runtime complexity of _O(n^2)_.
