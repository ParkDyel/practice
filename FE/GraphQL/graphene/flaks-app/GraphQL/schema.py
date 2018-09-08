import graphene

class Character(graphene.ObjectType):
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
    pn = graphene.String(pn=graphene.String(default_value="0"))

    def resolve_hello(self, info, name):
        return 'Hello ' + name

    def resolve_name(self, info, name):
        return name
    
    def resolve_pn(self, info, pn):
        return pn

class setDefualtMutation(graphene.Mutation):
    class Arguments:
        name = graphene.String()

    message = graphene.String()

    def mutate(root, info, name):
        default_value = name

        return "Success"

class Mutation(graphene.ObjectType):
    set_default = setDefualtMutation.Field()

schema = graphene.Schema(query=Query, mutation=Mutation)