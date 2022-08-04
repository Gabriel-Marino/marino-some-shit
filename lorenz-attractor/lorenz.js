const [beta, rho, sigma] = [8.0/3.0, 28.0, 10.0];

function f (state, t)
{
    const [x, y, z] = state;
    return [
        sigma * (y - x),
        x * (rho - z) - y,
        x * y - beta * z
    ];
}

const [total_time, step] = [24.0, 0.01];
const t = new Array(total_time/step + 1).fill(1).map((_, i) => i * step);

const state0 = [1.0, 1.0, 1.0];

const states = () => {
    let state = state0;
    let f1, f2, f3, f4;     // f is f[0]
    let g1, g2, g3, g4;     // g is f[1]
    let h1, h2, h3, h4;     // h is f[2]

    t.map((t_val) => {
        f1 = f(state, t_val)[0];
        g1 = f(state, t_val)[1];
        h1 = f(state, t_val)[2];

        state[0] += 0.5*step*f1;
        state[1] += 0.5*step*g1;
        state[2] += 0.5*step*h1;
        f2 = f(state, t_val)[0];
        g2 = f(state, t_val)[1];
        h2 = f(state, t_val)[2];

        state[0] += 0.5*step*f2;
        state[1] += 0.5*step*g2;
        state[2] += 0.5*step*h2;
        f3 = f(state, t_val)[0];
        g3 = f(state, t_val)[1];
        h3 = f(state, t_val)[2];

        state[0] += 0.5*step*f3;
        state[1] += 0.5*step*g3;
        state[2] += 0.5*step*h3;
        f4 = f(state, t_val)[0];
        g4 = f(state, t_val)[1];
        h4 = f(state, t_val)[2];

        state[0] += step*(f1+2.0*f2+2.0*f3+f4)/6.0;
        state[1] += step*(g1+2.0*g2+2.0*g3+g4)/6.0;
        state[2] += step*(h1+2.0*h2+2.0*h3+h4)/6.0;
    });
};