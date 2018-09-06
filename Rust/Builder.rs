// Width must always be greater than height!
struct HorizontalEllipse {
    width: f64,
    height: f64,
}

impl HorizontalEllipse {
    fn area(&self) -> f64 {
        std::f64::consts::PI * (self.width / 2.0) * (self.height / 2.0)
    }
}

struct HorizontalEllipseBuilder {
    width: f64,
    height: f64,
}

impl HorizontalEllipseBuilder {
    fn new() -> HorizontalEllipseBuilder {
        HorizontalEllipseBuilder {
            width: 0.0,
            height: 0.0,
        }
    }

    fn width(&mut self, width: f64) -> &mut HorizontalEllipseBuilder {
        self.width = width;
        self
    }

    fn height(&mut self, height: f64) -> &mut HorizontalEllipseBuilder {
        self.height = height;
        self
    }

    fn finalize(&self) -> Result<HorizontalEllipse, String> {
        let HorizontalEllipseBuilder { height, width } = *self;
        if height >= width {
            Err("This is not horizontal".into())
        } else {
            Ok(HorizontalEllipse { width, height })
        }
    }
}

fn main() {
    let c = HorizontalEllipseBuilder::new()
        .width(1.0)
        .height(2.0)
        .finalize()
        .expect("not a valid ellipse");

    println!("area: {}", c.area());
    println!("width: {}", c.width);
    println!("height: {}", c.height);
}