#![allow(dead_code)]

use std::io::BufRead;
use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hm: HashMap<i32, i32> = HashMap::new();
        for n in nums.iter() {
            if let Some(_c) = hm.get(n) {
                return true;
            }
            hm.entry(*n)
                .and_modify(|c| *c += 1)
                .or_insert(1);
        }
        false
    }

    fn load_from(file_path: &str) -> Vec<i32> {
        let p = env!("CARGO_MANIFEST_DIR").to_string() + "/target/" + file_path;
        let file = std::fs::File::open(p)
            .expect("file can't be found!");
        let reader = std::io::BufReader::new(file);

        reader.lines()
            .flat_map(|l| {
                l
                    .unwrap()
                    .split(',')
                    .into_iter()
                    .map(|s| s.parse::<i32>().unwrap())
                    .collect::<Vec<_>>()
            })
            .collect::<Vec<_>>()
    }
}

#[test]
fn prb217()
{
    let r1 = true;
    let nums1 = vec![1, 2, 3, 1];
    let r2 = false;
    let nums2 = vec![1, 2, 3, 4];
    let r3 = true;
    let nums3 = vec![1, 1, 1, 3, 3, 4, 3, 2, 4, 2];
    assert_eq!(r1, Solution::contains_duplicate(nums1));
    assert_eq!(r2, Solution::contains_duplicate(nums2));
    assert_eq!(r3, Solution::contains_duplicate(nums3));
    let r4 = false;
    let nums4 = Solution::load_from("prb217.txt");
    assert_eq!(r4, Solution::contains_duplicate(nums4));
}

/*
   217. Contains Duplicate

   Given an integer array nums, return true if any value appears at least twice
   in the array, and return false if every element is distinct.
 */
