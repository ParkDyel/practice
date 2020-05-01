class jsList {
  constructor(...args){
    this.bucket = []
    if( Array.isArray(args[0])){
      args.forEach(el=>{
        if(Array.isArray(el)) {
          this.bucket = this.bucket.concat(el)
        } else {
          this.bucket.push(el);
        }
      })
    } else {
      this.bucket = this.bucket.concat(args);
    }
  }

  async length(){
    return this.bucket.length
  }

  async add(el, idx){
    if(idx != undefined && await this.length() > idx){
      this.bucket.splice(idx, 0, el)
    } else {
      this.bucket.push(el);
    }
  }
}

const main = async () => {
  let $_list = await new jsList(1,2,3)
  // let $_list2 = await new jsList([1,2,3], 4, 5)
  console.log($_list)
  // console.log($_list2)
  console.log(await $_list.length())
  await $_list.add(4)
  console.log($_list)
  await $_list.add(0,2)
  await $_list.add(0,7)
  console.log($_list)
}

if (require.main === module) {
  main();
}