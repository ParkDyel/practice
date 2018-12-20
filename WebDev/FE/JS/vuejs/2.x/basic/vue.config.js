module.exports = {
  baseUrl: '',
  lintOnSave: process.env.NODE_ENV !== 'production',
  // chainWebpack: config => {
  //   config.module
  //     .rule('')
  //     .use('file-loader')
  //       .loader('file-loader')
  //       .tap(options => {
  //         options.publicPath = ''
  //         options.name = ''
  //         return options 
  //       })
  // } 
  
  // module: {
  //   rules: [{
  //     test: /\.png$/,
  //     loader: 'file-loader',
  //     options: {
  //       publicPath: './src/assets/images/',
  //       name: '[name].[ext]?[hash]',
  //     }
  //   }]
  // } 
}
