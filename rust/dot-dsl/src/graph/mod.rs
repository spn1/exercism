pub mod graph_items;

use std::collections::HashMap;
use graph_items::edge::Edge;
use graph_items::node::Node;

pub struct Graph {
    pub nodes: Vec<Node>,
    pub edges: Vec<Edge>,
    pub attrs: HashMap<String, String>,
}

impl Graph {
    pub fn new() -> Self {
        Self {
            nodes: Vec::new(),
            edges: Vec::new(),
            attrs: HashMap::new(),
        }
    }

    pub fn is_empty(&self) -> bool {
        self.nodes.is_empty() && self.edges.is_empty() && self.attrs.is_empty()
    }

    pub fn node(&self, key: &str) -> Option<&Node> {
        self.nodes.iter().find(|node: &&Node| node.value == key)
    }

    pub fn attr(&self, key: &str) -> Option<&str> {
        self.attrs.get(key).map(|attr: &String| attr.as_str())
    }

    pub fn with_nodes(mut self, nodes: &[Node]) -> Self {
        self.nodes = nodes.to_vec();
        self
    }

    pub fn with_edges(mut self, edges: &[Edge]) -> Self {
        self.edges = edges.to_vec();
        self
    }

    pub fn with_attrs(mut self, attributes: &[(&str, &str)]) -> Self {
        self.attrs.clear();
        attributes
            .iter()
            .for_each(
                |(key, value)| {
                    self.attrs.insert(key.to_string(), value.to_string());
                }
            );
        self
    }
}