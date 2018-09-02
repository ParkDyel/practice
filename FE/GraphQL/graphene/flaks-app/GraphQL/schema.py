import graphene

class Character(graphene.Interface):
    name = graphene.String()
    PN = graphene.String()

User = []

Dyel = Character(
    name='Park DongYoung',
    PN='010-9284-6546',
)

User.append(Dyel)

class Query(graphene.ObjectType):
    hello = graphene.String(name=graphene.String(default_value="stranger"))
    name = graphene.String(name=graphene.String(default_value="stranger"))

    def resolve_hello(self, info, name):
        return 'Hello ' + name

    def 

schema = graphene.Schema(query=Query)