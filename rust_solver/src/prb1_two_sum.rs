#![allow(dead_code)]

use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();        
        for (i, n) in nums.iter().enumerate() {
            if let Some(x) = map.get(&(target - n)) {
                return vec![*x as i32, i as i32];
            }
            else {
                map.insert(*n, i);
            }
        }
        vec![]
    }
}

#[test]
fn prb1()
{
    let r1 = vec![0, 1];
    let nums1 = vec![2, 7, 11, 15];
    let target1 = 9;
    let r2 = vec![1, 2];
    let nums2 = vec![3, 2, 4];
    let target2 = 6;
    let r3 = vec![0, 1];
    let nums3 = vec![3, 3];
    let target3 = 6;
    assert_eq!(r1, Solution::two_sum(nums1, target1));
    assert_eq!(r2, Solution::two_sum(nums2, target2));
    assert_eq!(r3, Solution::two_sum(nums3, target3));
}
