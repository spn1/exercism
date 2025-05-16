
use std::collections::HashMap;

#[derive(Clone, Debug, PartialEq)]
pub struct Node{
    pub value: String,
    pub attrs: HashMap<String, String>,
}

impl Node {
    pub fn new(value: &str) -> Self {
        Node {
            value: value.to_string(),
            attrs:  HashMap::new(),
        }
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

    pub fn attr(&self, key: &str) -> Option<&str> {
        self.attrs.get(key).map(|attr: &String| attr.as_str())
    }
}