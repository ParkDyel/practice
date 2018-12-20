<template lang="pug">
.container
    img(src="../assets/image/logo.png")
    //- img(style='{ "width" : "200px" , "height" : "200px" }' :style="{backgroundImage : logoSrcUrl }")
    //- img(:src="logoSrc")
    //- img(:src="logoSrcUrl")
    //- img(:src="logoSrcRequire")
    img(:src="getImg(this.$props.imgSrc)")
    img(:src="stringRequire")
    //- img(:src="logoSrcData")
    //- img(:src="logoSrcDataUrl")
</template>

<script>
export default {
    props : {
        "imageDir" : String,
        "imgSrc" : String,
    },
    data(){
        return {
            logoSrcData : '',
        }
    },
    computed : {
        logoSrc(){
            return this.$props.imageDir + this.$props.imgSrc
        },
        logoSrcRequire(){
            return require(this.logoSrcData)
        },
        stringRequire(){
            return require("../assets/image/logo.png")
        },
        logoSrcUrl(){
            return `url(${this.$props.imageDir}${this.$props.imgSrc})`
        },
        logoSrcDataUrl(){
            return `url(${this.logoSrcData})`
        },
    },
    methods : {
        getImg(fileName){
            return require('../assets/image/' + fileName)
        }
    },
    created() {
        console.log(this.$props.imageDir) // ../assets/image/
        console.log(this.$props.imgSrc) // logo.png
        this.$data.logoSrcData = this.$props.imageDir + this.$props.imgSrc
        console.log(this.logoSrcData) // ../assets/image/logo.png
    },
}
</script>

<style scoped>

</style>

