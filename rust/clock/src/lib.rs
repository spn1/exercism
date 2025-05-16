// pub mod exercism {
    use std::fmt;

    #[derive(Debug)]
    pub struct Clock {
        hours: i32,
        minutes:i32
    }

    impl fmt::Display for Clock {
        fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
            write!(formatter, "{:0>2}:{:0>2}", self.hours, self.minutes)
        }
    }

    impl PartialEq for Clock {
        fn eq(&self, other: &Self) -> bool {
            self.hours == other.hours && self.minutes == other.minutes
        }
    }

    impl Clock {
        pub fn new(hours: i32, minutes: i32) -> Self {
            let mut clock = Clock { hours, minutes };
            println!("🚩 clock: {clock}");
            clock.handle_overflow();
            clock
        }

        pub fn add_minutes(&self, minutes: i32) -> Self {
            println!("🚩 self: {self}");
            println!("🚩 minutes: {minutes}");
            let mut new = Clock::new(self.hours, self.minutes + minutes);

            new.handle_overflow();

            new
        }

        fn handle_overflow(&mut self) {
            if self.minutes >= 60 {
                let minutes_remainder = self.minutes % 60;
                let hours_rollover = self.minutes / 60;
                self.minutes = minutes_remainder;
                self.hours += hours_rollover;
            }

            if self.minutes < 0 {
                let minutes_remainder = (self.minutes % 60 + 60) % 60;
                let hours_rollunder = (self.minutes - minutes_remainder) / 60;
                self.minutes = minutes_remainder;
                self.hours += hours_rollunder;
            }

            if self.hours >= 24 {
                self.hours %= 24;
            }

            if self.hours < 0 {
                self.hours = (self.hours % 24 + 24) % 24;
            }
        }
    }
// }
