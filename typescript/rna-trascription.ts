console.log(process.argv);

// const x = (dna) => {
    const obj = {
        'G': 'C',
        'C': 'G',
        'T': 'A',
        'A': 'U'
    }
    
//     const splitLetters = dna.split('');
//     const rna = [];

//     splitLetters.forEach(e => rna.push(obj[e]));

//     return rna.join('');
// }

const x = (dna) => { 
    return dna.split('').map(letter => (obj[letter])).join('');
}

console.log(`RNA = ${x(process.argv[2])}`);
