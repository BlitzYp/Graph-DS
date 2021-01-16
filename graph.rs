/* 
WARNING THIS IS A VERY BAD IMPLEMENTATION, 
IT DOESNT EVEN WORK PROPERLY 
BUT I HAD TO MAKE A RUST VERSION OF THE GRAPH DS 
*/

use std::collections::HashMap;

struct Graph {
    data: HashMap<&'static str, Vec<String>>,
    size: u32,
}

impl Graph {
    fn new() -> Self {
        Graph {
            data: HashMap::new(),
            size: 0,
        }
    }
    fn create(&mut self, key: &'static str) {
        self.data.insert(key, Vec::new());
        self.size += 1;
    }

    fn get(&mut self, key: &'static str) {
        println!("{:?}", self.data[key])
    }

    fn add_edge(&mut self, key: &'static str, key2: &'static str) {
        let mut vec1 = self.data[key].clone();
        let mut vec2 = self.data[key2].clone();
        vec1.push(String::from(key2));
        vec2.push(String::from(key));
        self.data.entry(key).or_insert(vec1.to_vec());
        self.data.entry(key2).or_insert(vec2.to_vec());
    }

    fn bfs<'a>(&mut self, starting_node: &'a str, data: &mut Vec<String>) {
        let mut visited: Vec<String> = Vec::new();
        let mut queue: Vec<String> = Vec::new();

        visited.push(String::from(starting_node));
        queue.push(String::from(starting_node));

        while queue.len() != 0 {
            let current = queue.remove(0);
            let current_vertex = &self.data[current.as_str()];
            for i in current_vertex.iter() {
                if !visited.contains(i) {
                    queue.push(i.to_string());
                    visited.push(i.to_string());
                    data.push(i.to_string());
                    println!("{}", i);
                }
            }
        }
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.create("Apples");
    graph.create("Pears");
    graph.add_edge("Apples", "Pears");
    let mut data = Vec::with_capacity(graph.size as usize);
    graph.bfs("Apples", &mut data);
}
