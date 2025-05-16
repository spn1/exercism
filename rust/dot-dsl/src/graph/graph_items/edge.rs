use std::collections::HashMap;

#[derive(Clone, Debug, PartialEq)]
pub struct Edge {
    pub start: String,
    pub end: String,
    pub attrs: HashMap<String, String>,
}

impl Edge {
    pub fn new(start: &str, end: &str) -> Self {
        Edge {
            start: start.to_string(),
            end: end.to_string(),
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