<template lang="pug">
    .header_wrapper
        router-link(to="/Home") Home
        router-link(to="/About") About
        router-link(to="/NotFound") NotFound
        img(class="logo" alt="logo" src="../assets/image/logo.png")

</template>

<style>
.header_wrapper {
    display:flex;
    justify-content: flex-end;
    vertical-align: middle;
}

.header_wrapper * {
    text-align: center;
    flex-basis: 5%;
}

.header_wrapper .logo {
  width:32px;
  height:32px;
}

/* Medium screens */
@media all and (max-width: 800px) {
  .header_wrapper  {
    /* When on medium sized screens, we center it by evenly distributing empty space around items */
    justify-content: space-around;
  }
}

/* Small screens */
@media all and (max-width: 500px) {
  .header_wrapper  {
    /* On small screens, we are no longer using row direction but column */
    flex-direction: column;
  }
}
</style>

<script>
// import Logo from '../assets/logo.png'

export default {
  name: 'gnb',
  data() {
    return {
      // Logo : Logo
    }
  }
}
</script>
