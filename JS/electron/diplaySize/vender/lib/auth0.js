<script src="https://cdn.auth0.com/js/lock/10.8.0/lock.min.js"></script>
<script>
  var lock = new Auth0Lock(
    "7I3KXNi6ZeBq6oL0xnlfk1SrW6KntwR5",
    "pwdlessdemo.auth0.com",
    {
      allowedConnections: ["Username-Password-Authentication","google-oauth2","facebook"],
    rememberLastLogin: false,
socialButtonStyle: "big",
theme: {"primaryColor":"#40DF7D"},
languageDictionary: {"title":"Auth0"},
language: "en"
    }
  );

  lock.show();
</script>