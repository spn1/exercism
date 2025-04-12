// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(Debug)]
pub struct Duration(u64);

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Self(s)
    }
}

const EARTH_YEAR_IN_SECONDS: f64 = 31557600.0;

pub trait Planet {
    const ORBITAL_PERIOD_RATIO: f64;
    fn years_during(d: &Duration) -> f64 {
        (d.0 as f64) / EARTH_YEAR_IN_SECONDS / Self::ORBITAL_PERIOD_RATIO
    }
}

macro_rules! implement_planet {
    ($planet:tt, $period:expr) => {
        pub struct $planet; 
        impl Planet for $planet {
            const ORBITAL_PERIOD_RATIO: f64 = $period;
        }
    };
}

implement_planet!(Mercury, 0.2408467);
implement_planet!(Venus, 0.61519726);
implement_planet!(Earth, 1.0);
implement_planet!(Mars, 1.8808158);
implement_planet!(Jupiter, 11.862615);
implement_planet!(Saturn, 29.447498);
implement_planet!(Uranus, 84.016846);
implement_planet!(Neptune, 164.79132);
